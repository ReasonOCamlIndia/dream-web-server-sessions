let () = print_endline("Hello, World!");

let hello_route_handler = _request => Dream.html("<h1>hello, world</h1>");

let hello_route: Dream.route = Dream.get("/", hello_route_handler);

let handler = Dream.router([hello_route]);

// request => promise(response)
Dream.run(~port=8000, ~interface="localhost", handler);
