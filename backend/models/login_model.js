const db = require('../database');

const login = {
    checkPassword:function(login_username, callback){
        return db.query('select bankPIN from card where cardID=?', login_username,callback);
    }  
};

module.exports=login;