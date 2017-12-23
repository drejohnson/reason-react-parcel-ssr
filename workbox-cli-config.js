module.exports = {
  globDirectory: './',
  globPatterns: [
    'dist/**/*.{js,html,png,svg}',
    'static/**/*.{json,ico,png,svg}'
  ],
  swSrc: 'src/utils/sw.js',
  swDest: 'dist/client/sw.js',
  globIgnores: ['../workbox-cli-config.js', 'index.html']
}
