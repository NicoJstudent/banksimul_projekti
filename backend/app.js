var express = require('express');
var path = require('path');
var cookieParser = require('cookie-parser');
var logger = require('morgan');
const dotenv=require('dotenv');
const jwt = require('jsonwebtoken');

var indexRouter = require('./routes/index');
var accountRouter = require('./routes/account');
var transactionsRouter = require('./routes/transactions');
var customerRouter = require('./routes/customer');
var cardRouter = require('./routes/card');
var loginRouter = require('./routes/login');


var app = express();
dotenv.config();

app.use(logger('dev'));
app.use(express.json());
app.use(express.urlencoded({ extended: false }));
app.use(cookieParser());
app.use(express.static(path.join(__dirname, 'public')));

app.use('/', indexRouter);
app.use('/login', loginRouter);
app.use(authenticateToken);
app.use('/card',cardRouter);
app.use('/account', accountRouter);
app.use('/transactions', transactionsRouter);
app.use('/customer', customerRouter);

function authenticateToken(req, res, next) {
    const authHeader = req.headers['authorization']
    const token = authHeader && authHeader.split(' ')[1]
  
    console.log("token = "+token);
    if (token == null) return res.sendStatus(401)
  
    jwt.verify(token, process.env.MY_TOKEN, (err, user) => {
      console.log(err)
  
      if (err) return res.sendStatus(403)
  
      req.user = user
  
      next()
    })
  }

module.exports = app;
