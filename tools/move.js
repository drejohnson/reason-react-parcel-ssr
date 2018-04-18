const path = require('path')
const fs = require('fs-extra')
const config = require('./config')

const mv = async (i, o) => {
  const exists = await fs.pathExists(i)
  if (exists) {
    await fs.moveSync(config.resolveApp(i), config.resolveApp(o), {
      overwrite: true
    })
  }
}

mv('lib/js/src/server/server.bs.js', 'dist/server/index.js')
