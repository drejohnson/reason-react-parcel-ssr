let client_bundle = ! Config.Env.isDev ? {j|client.js|j} : {j|client.bs.js|j};

let make = (~content, ~title, ~meta, ~link, ~script, ~htmlAttr, ()) => {j|
  <!DOCTYPE html>
    <html $htmlAttr>
      <head>
        $title
        $meta
        $link
        $script
      </head>
      <body>
        <div id="root">$content</div>
        <script src="/assets/client.js"></script>
      </body>
    </html>
|j};
