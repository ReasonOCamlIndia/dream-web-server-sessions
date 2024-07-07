[@alert "-all--all+browser_only"];
let%browser_only handleLinkAnchorOnClick = (href, e) => {
  React.Event.Mouse.preventDefault(e);
  ReasonReactRouter.push(href);
};


[@react.component]
let make = (~href, ~children) => {
  <a onClick={handleLinkAnchorOnClick(href)} href> {children} </a>;
};
