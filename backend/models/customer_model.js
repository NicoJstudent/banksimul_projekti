const db = require('../database');

const customer = {
  getAll: function(callback) {
    return db.query('select * from customer', callback);
  },
  getById: function(id, callback) {
    return db.query('select * from customer where idCustomer=?', [id], callback);
  },
  add: function(customer, callback) {
    return db.query(
      'insert into customer (Firstname,Lastname,Address) values(?,?,?)',
      [customer.Firstname, customer.Lastname, customer.Address],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from customer where idCustomer=?', [id], callback);
  },
  update: function(id, customer, callback) {
    return db.query(
      'update customer set Firstname=?,Lastname=?,Address=? where idCustomer=?',
      [customer.Firstname, customer.Lastname, customer.Address, id],
      callback
    );
  }
};
module.exports = customer;