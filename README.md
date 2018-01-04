# Reason Parcel SSR

> A basic starting point for building universal web apps with ReasonReact bundled with Parcel.

> Far from refined. Used as a basis to learn ReasonML and POC for server side rendering with ReasonReact and Parcel

## Features

* [x] [ReasonReact](https://reasonml.github.io/reason-react/)
* [x] PWA - [Workbox](https://developers.google.com/web/tools/workbox/)
* [x] SSR - Server side rendering
* [x] [Parcel - zero config web app bundler](https://parceljs.org/)
* [x] [React Router v4](https://reacttraining.com/react-router/api) *[bindings](https://github.com/reasonml-community/bs-react-router) (Waiting for Reason Router solution)
* [x] [React Helmet](https://github.com/nfl/react-helmet) bindings

**Check out the [Universal-Router](https://github.com/kriasoft/universal-router) branch**

## Quick start

* Use install dependencies: `yarn`
* For dev mode without ssr run `yarn dev` or `npm run dev`, open browser, the app should be running at: http://localhost:1234.
* To build run: `yarn build` or `npm run build`
* To build and run use: `yarn build` or `npm run build` followed by `yarn start` or `npm start`

## TODO

* [ ] Add "CSS-In-Reason" library. Either [bs-css](https://github.com/SentiaAnalytics/bs-css) or [bs-react-fela](https://github.com/astrada/bs-react-fela).