const db = require('../database');

const account = {
  getAll: function(callback) {
    return db.query('select * from account', callback);
  },
  getById: function(id, callback) {
    return db.query('select * from account where idAccount=?', [id], callback);
  },
  add: function(account, callback) {
    return db.query(
      'insert into account (balance,debit_limit) values(?,?)',
      [account.balance, account.debit_limit],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from account where idAccount=?', [id], callback);
  },
  update: function(id, account, callback) {
    return db.query(
      'update account set balance=?,debit_limit=? where idAccount=?',
      [account.balance, account.debit_limit, id],
      callback
    );
  }
};
module.exports = account;