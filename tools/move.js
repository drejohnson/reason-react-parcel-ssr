const path = require('path')
const fs = require('fs-extra')

const appDirectory = fs.realpathSync(process.cwd())
const resolveApp = relativePath => path.resolve(appDirectory, relativePath)

fs.moveSync(
  resolveApp('dist/client/index.html'),
  resolveApp('dist/index.html'),
  {
    overwrite: true
  }
)
