let component = ReasonReact.statelessComponent("Header");

let make = _children => {
  ...component,
  render: _self =>
    <Fragment>
      <header>
        <h1>
          <a href="/"> ("ReasonReact Fullstack Parcel" |> Utils.text) </a>
        </h1>
        <nav>
          <Link href="/" label="Home" />
          <Link href="/about" label="About" />
        </nav>
      </header>
    </Fragment>,
};