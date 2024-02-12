const db = require('../database');
const bcrypt = require('bcryptjs');

const saltRounds = 10;

const card = {
    getAll: function (callback) {
        return db.query('select * from card', callback);
    },
    getById: function (id, callback) {
        return db.query('select * from card where idCard=?', [id], callback);
    },
    add: function (card, callback) {
        bcrypt.hash(card.bankPIN, saltRounds, function (err, hashed_password) {
            return db.query('insert into card (card_type,bankPIN,cardID,Customer_idCustomer,Account_idAccount) values(?,?,?,?,?)',
                [card.card_type, hashed_password, card.cardID, card.Customer_idCustomer, card.Account_idAccount],
                callback);
        });
    },
    delete: function (id, callback) {
        return db.query('delete from card where idCard=?', [id], callback);
    },
    update: function (id, card, callback) {
        bcrypt.hash(card.bankPIN, saltRounds, function (err, hashed_password) {
            return db.query(
                'update card set card_type=?,bankPIN=?,cardID=?,Customer_idCustomer=?,Account_idAccount=? where idCard=?',
                [card.card_type, hashed_password, card.cardID, card.Customer_idCustomer, card.Account_idAccount, id],
                callback);
        });
    }
};
module.exports = card;