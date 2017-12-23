const path = require('path')
const fs = require('fs-extra')

const appDirectory = fs.realpathSync(process.cwd())
const resolveApp = relativePath => path.resolve(appDirectory, relativePath)

fs.emptyDirSync(resolveApp('dist'))
