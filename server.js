const express = require("express");
const bodyParser = require("body-parser");
const twilio = require("twilio");

// Twilio credentials
const accountSid = 'ACXXXXXXXXXXXXXX';  // Replace with your Twilio Account SID
const authToken = '866XXXXXXXXXXXXXX';
const twilioClient = twilio(accountSid, authToken);

// Express server setup
const app = express();
app.use(bodyParser.json());

const PORT = 3000;

// Endpoint for receiving data from ESP32
app.post("/full-bin", (req, res) => {
  const { status } = req.body;

  if (status === "full") {
    sendSMS();
    res.send("SMS sent: Bin is full");
  } else {
    res.send("Bin status not full");
  }
});

// Function to send SMS via Twilio
function sendSMS() {
  twilioClient.messages
    .create({
      body: "Alert: The waste bin is full. Please empty it.",
      from: "+125XXXXX", // YOUR TWILO NUMBER
      to: "+9188XXXXXXX", // RECIPENT NUMBER
    })
    .then((message) => console.log(`SMS sent: ${message.sid}`))
    .catch((error) => console.error(error));
}

app.listen(PORT, () => {
  console.log(`Server running on port ${PORT}`);
});




