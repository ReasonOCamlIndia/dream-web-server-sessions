let home = () => Routes.(nil); // '/'
let hello = () => Routes.(s("hello") /? nil); // /hello

let homeRoute = Routes.(home() @--> (() => {
  print_endline("in home page");
  <App />;
}));

let helloRoute = Routes.(hello() @--> (() => {
  print_endline("in hello view");
  <p> {React.string("In Hello")} </p>
}));

let routes = Routes.one_of([homeRoute, helloRoute]);
