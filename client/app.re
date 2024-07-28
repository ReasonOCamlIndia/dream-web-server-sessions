module Main = {
  [@react.component]
    let make = () => {
      let target =
        ReasonReactRouter.useUrl().path
     |> String.concat("/");
      switch (Routes.match'(Reason_india_website_js.AppRouter.routes, ~target)) {
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
