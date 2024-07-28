let home = () => Routes.(nil); // '/'
let hello = () => Routes.(s("hello") /? nil); // /hello

let homeRoute = Routes.(home() @--> (() => {
  print_endline("in home page");
  <Reason_india_website_js.App />;
}));

let helloRoute = Routes.(hello() @--> (() => {
  print_endline("in hello view");
  <p> {React.string("In Hello")} </p>
}));

let routes = Routes.one_of([homeRoute, helloRoute]);

module Main = {
  [@react.component]
    let make = () => {
      let target =
        ReasonReactRouter.useUrl().path
      |> String.concat("/");
      switch (Routes.match'(routes, ~target)) {
      | Routes.FullMatch(e) => e()
      | Routes.MatchWithTrailingSlash(e) => e()
      | Routes.NoMatch => <p> {React.string("404")} </p>
      };
    }
};

switch (ReactDOM.querySelector("#root")) {
| Some(el) =>
  ReactDOM.Client.createRoot(el)->ReactDOM.Client.render(<Main />)
| None => ()
};
