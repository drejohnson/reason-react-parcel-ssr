/* [@bs.module "../static/images/logo.svg"] external logo : string = "default"; */
let component = ReasonReact.statelessComponent("Header");

let make = (_children) => {
  ...component,
  render: (_self) => <header> /*<img src=logo alt="logo" width="200px" />*/ <Nav /> </header>
};