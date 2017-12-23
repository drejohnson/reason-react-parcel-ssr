const path = require('path')
const fs = require('fs-extra')

const appDirectory = fs.realpathSync(process.cwd())
const resolveApp = relativePath => path.resolve(appDirectory, relativePath)

function copyStaticDir () {
  fs.copySync(resolveApp('static'), resolveApp('dist'), {
    dereference: true,
    filter: file => file !== resolveApp('static/index.html')
  })
}

copyStaticDir()
