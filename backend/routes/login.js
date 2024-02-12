const express = require('express');
const router = express.Router();
const bcrypt = require('bcryptjs');
const login = require('../models/login_model');
const jwt = require('jsonwebtoken');
const dotenv = require('dotenv');

router.post('/', 
  function(request, response) {
    if(request.body.cardID && request.body.bankPIN){
      const user = request.body.cardID;
      const pass = request.body.bankPIN;
      
        login.checkPassword(user, function(dbError, dbResult) {
          if(dbError){
            response.json(dbError);
          }
          else{
            if (dbResult.length > 0) {
              bcrypt.compare(pass,dbResult[0].bankPIN, function(dbError,compareResult) {
                if(compareResult) {
                  console.log("succes");
                  const token = generateAccessToken({ cardID: user });
                  response.send(token);
                }
                else {
                    console.log("wrong password");
                    response.send(false);
                }			
              }
              );
            }
            else{
              console.log("user does not exists");
              response.send(false);
            }
          }
          }
        );
      }
    else{
      console.log("cardID or bankPIN missing");
      response.send(false);
    }
  }
);

function generateAccessToken(cardID) {
  dotenv.config();
  return jwt.sign(cardID, process.env.MY_TOKEN, { expiresIn: '1800s' });
}

module.exports=router;