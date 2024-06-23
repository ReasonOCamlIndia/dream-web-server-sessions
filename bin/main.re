module Page = {
  [@react.component]
  let make = (~children, ~scripts=[], ~stylesheet) => {
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
        <div id="root" style={ReactDOM.Style.make(~height="100%", ())}>
          children
        </div>
        {scripts |> List.map(src => <script src />) |> React.list}
      </body>
    </html>;
  };
};

let hello_route_handler = _request => {
  let stylesheet = CssJs.render_style_tag();
  Dream.html(
    ReactDOM.renderToString(
      <Page stylesheet scripts=["/static/app.js"]>
        <Reason_india_website_native.App />
      </Page>,
    ),
  );
};

let hello_route: Dream.route = Dream.get("/", hello_route_handler);
let statics_route: Dream.route =
  Dream.get("/static/**", Dream.static("./static"));

let handler = Dream.router([hello_route, statics_route]);

// request => promise(response)
Dream.run(~port=8000, ~interface="localhost", handler);
