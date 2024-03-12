const nodemailer = require('nodemailer')
const path = require('path')

console.log(__dirname)
console.log(path.resolve(__dirname))


const testmail = async function() {
  let testEmailAccount = await nodemailer.createTestAccount()

  let transporter = nodemailer.createTransport({
    host: 'smtp.ethereal.email',
    port: 587,
    secure: false,
    auth: {
      user: testEmailAccount.user,
      pass: testEmailAccount.pass,
    },
  })


  let mailOptions = {
    from: '"Node js" <ar.z.v@yandex.ru>',
    to: 'user@example.com, user@example.com',
    subject: 'Message from Node js',
    text: 'This message was sent from Node js server.',
    html:
      'ここではてがみがあります',
    attachments: [
      { filename: 'sometext.txt', path: 'C:\\Users\\User\\Code\\smilesite\\sometext.txt' },

    ],
  }

  let result = await transporter.sendMail(mailOptions, (error, info) => {
    if (error) {
      return console.log(error);
      // return console.log('Error');
    } else {
      console.log('Message sent: %s', info.messageId);
      console.log('Preview URL: %s', nodemailer.getTestMessageUrl(info));
    }

  })
  console.log(result);


}

testmail();

/*

*/
