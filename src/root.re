open ReactRouter;

let make = () =>
  <div>
    <ReactHelmet>
      <meta charSet="utf-8" />
      <meta name="viewport" content="width=device-width, initial-scale=1" />
      <meta name="theme-color" content="#000000" />
      <link rel="manifest" href="/manifest.json" />
      <link rel="shortcut icon" href="/favicon.ico" />
      <title> (Utils.text("ReasonReact Starter")) </title>
      <meta
        name="description"
        content="Reason lets you write simple, fast and quality type safe code while leveraging both the JavaScript & OCaml ecosystems."
      />
    </ReactHelmet>
    <Header />
    <Switch>
      <Route path="/" exact=true component=(() => <Home />) />
      <Route path="/about" exact=true component=(() => <About />) />
    </Switch>
  </div>;