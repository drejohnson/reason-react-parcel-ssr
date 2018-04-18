const path = require('path')
const fs = require('fs-extra')
const config = require('./config')

fs.copySync(config.resolveApp('public'), config.resolveApp('dist/public'), {
  dereference: true
})
