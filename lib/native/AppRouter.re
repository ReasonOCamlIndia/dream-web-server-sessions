let home = () => Routes.(nil); // '/'
let hello = () => Routes.(s("hello") /? nil); // /hello

let homeRoute = Routes.(home() @--> (() => {
  print_endline("in home page");
  <App />;
}));



module HelloContainer = [%styled.p
   {|
     color: red;
|}
];

let helloRoute = Routes.(hello() @--> (() => {
  print_endline("in hello view");
  <>
  <HelloContainer> {React.string("In Hello")} </HelloContainer>
    <Link href="/">{React.string("back home")}</Link>
  </>
}));

let routes = Routes.one_of([homeRoute, helloRoute]);
