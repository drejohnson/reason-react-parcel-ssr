importScripts(
  'https://unpkg.com/workbox-sw@2.1.2/build/importScripts/workbox-sw.prod.v2.1.2.js'
)

const workboxSW = new self.WorkboxSW({ clientsClaim: true })
workboxSW.precache([])
workboxSW.precache(['https://fonts.googleapis.com/css?family=Lato'])

workboxSW.router.registerRoute(
  /(.)(?:png|jpg|webp|svg)/,
  workboxSW.strategies.cacheFirst({
    cacheName: 'images-cache',
    cacheExpiration: {
      maxEntries: 50
    },
    cacheableResponse: { statuses: [0, 200] }
  })
)

workboxSW.router.registerRoute(
  '/^(https?.*)/',
  workboxSW.strategies.networkFirst({
    cacheName: 'cache-all',
    cacheExpiration: {
      maxEntries: 50
    },
    networkTimeoutSeconds: 3
  })
)

workboxSW.router.setDefaultHandler({
  handler: workboxSW.strategies.staleWhileRevalidate()
})
