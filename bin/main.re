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

let hello_route_handler = _request => {
  let appHTMLString =
    ReactDOM.renderToString(<Reason_india_website_native.App />);
  Dream.html(
    ReactDOM.renderToString(
      <Page scripts=["/static/app.js"] appHTMLString />,
    ),
  );
};

let hello_route: Dream.route = Dream.get("/", hello_route_handler);
let statics_route: Dream.route =
  Dream.get("/static/**", Dream.static("./static"));

let handler = Dream.router([hello_route, statics_route]);

// request => promise(response)
Dream.run(~port=8000, ~interface="localhost", handler);
