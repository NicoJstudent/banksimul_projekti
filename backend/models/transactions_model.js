const db = require('../database');

const transactions = {
  getAll: function(callback) {
    return db.query('select * from transactions', callback);
  },
  getById: function(id, callback) {
    return db.query('select * from transactions where idTransactions=?', [id], callback);
  },
  add: function(transactions, callback) {
    return db.query(
      'insert into transactions (amount,date_time,type,Account_idAccount) values(?,?,?,?)',
      [transactions.amount, transactions.date_time, transactions.type, transactions.Account_idAccount],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from transactions where idTransactions=?', [id], callback);
  },
  update: function(id, transactions, callback) {
    return db.query(
      'update transactions set amount=?,date_time=?,type=?, Account_idAccount=? where idTransactions=?',
      [transactions.amount, transactions.date_time, transactions.type, transactions.Account_idAccount, id],
      callback
    );
  }
};
module.exports = transactions;