let component = ReasonReact.statelessComponent("Box");

let make = (~_as=?, children) => {
  ...component,
  render: (_self) => {
    let tag =
      switch _as {
      | Some(tag) => tag
      | None => "div"
      };
    ReasonReact.createDomElement(tag, ~props=Js.Obj.empty(), children)
  }
};