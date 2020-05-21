var addon = require('bindings')('native-utils');

module.exports = {
  hostname: addon.host(),
  ipaddr: addon.ip,
  add: addon.add,
  minus: addon.minus,
  find: addon.find,
  ...addon
};
