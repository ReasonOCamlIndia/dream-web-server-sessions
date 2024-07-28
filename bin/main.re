[@alert "-all--all+deprecated"];
module Page = {
  [@react.component]
  let make = (~scripts=[], ~appHTMLString) => {
    print_endline("Inside component <<<<<<");
    let stylesheet = CssJs.render_style_tag();
    <html style={ReactDOM.Style.make(~height="100%", ())}>
      <head>
        <meta charSet="UTF-8" />
        <meta
          name="viewport"
          content="width=device-width, initial-scale=1.0"
        />
        <title> {React.string("Server Reason React demo")} </title>
        <link
          rel="shortcut icon"
          href="https://reasonml.github.io/img/icon_50.png"
        />
        <style> {React.string(stylesheet)} </style>
      </head>
      <body style={ReactDOM.Style.make(~height="100%", ())}>
        <div
          dangerouslySetInnerHTML={"__html": appHTMLString}
          id="root"
          style={ReactDOM.Style.make(~height="100%", ())}
        />
        {scripts |> List.map(src => <script src />) |> React.list}
      </body>
    </html>;
  };
};

let renderPage = reactElement => {
  let appHTMLString =
    ReactDOM.renderToString(reactElement);
  ReactDOM.renderToString(
    <Page scripts=["/static/app.js"] appHTMLString />,
  );
}




let hello_route_handler = request => {
  let target = request
  |> Dream.path
  |> List.filter(p => !String.equal("", p))
  |> String.concat("/");

  print_endline("---------------");
  print_endline(target);
  
  let reactElement = 
    switch (Routes.match'(Reason_india_website_native.AppRouter.routes, ~target)) {
    | Routes.FullMatch(e) => e()
    | Routes.MatchWithTrailingSlash(e) => e()
    | Routes.NoMatch => <p> {React.string("404")} </p>
    };

  Dream.html(
    renderPage(reactElement)
  );
};

let statics_route: Dream.route =
  Dream.get("/static/**", Dream.static("./static"));

let hello_route: Dream.route = Dream.get("/**", hello_route_handler);

let handler = Dream.router([statics_route, hello_route]);

// request => promise(response)
Dream.run(~port=8000, ~interface="localhost", handler);
