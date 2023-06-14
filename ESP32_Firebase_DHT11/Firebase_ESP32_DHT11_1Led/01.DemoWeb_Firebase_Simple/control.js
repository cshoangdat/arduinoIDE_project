

// Your web app's Firebase configuration
const firebaseConfig = {
  apiKey: "AIzaSyC2N2BagtDhspKYpzl8NU9XCbOdTawChe8",
  authDomain: "dht11-7cae8.firebaseapp.com",
  databaseURL: "https://dht11-7cae8-default-rtdb.firebaseio.com",
  projectId: "dht11-7cae8",
  storageBucket: "dht11-7cae8.appspot.com",
  messagingSenderId: "377719937077",
  appId: "1:377719937077:web:56276633943057e384b97c"
};
// Initialize Firebase
firebase.initializeApp(firebaseConfig);


// Auto load Temperature-------------------------
firebase.database().ref("/TT_IoT/nhietdo").on("value",function(snapshot){
  var nd = snapshot.val();  
  document.getElementById("nhietdo").innerHTML = nd;
  console.log(nd);
});

firebase.database().ref("/TT_IoT/doam").on("value",function(snapshot){
  var nd = snapshot.val();  
  document.getElementById("doam").innerHTML = nd;
  console.log(nd);
});

//Update Bulb status-----when reload website-------
firebase.database().ref("/TT_IoT").get().then((snapshot) => {
  if(snapshot.exists()){
    console.log(snapshot.val())

    var bulb_01_status = snapshot.val()
    if (bulb_01_status["BULB_01"] == "ON")
      document.getElementById("d01_img").src = "./img/light_bulb_on.png"
    else
      document.getElementById("d01_img").src = "./img/light_bulb_off.png"
  }
  else
    console.log("No data available!")
})

firebase.database().ref("/TT_IoT").get().then((snapshot) => {
  if(snapshot.exists()){
    console.log(snapshot.val())

    var bulb_02_status = snapshot.val()
    if (bulb_02_status["BULB_02"] == "ON")
      document.getElementById("d02_img").src = "./img/light_bulb_on.png"
    else
      document.getElementById("d02_img").src = "./img/light_bulb_off.png"
  }
  else
    console.log("No data available!")
})

firebase.database().ref("/TT_IoT").get().then((snapshot) => {
  if(snapshot.exists()){
    console.log(snapshot.val())

    var bulb_03_status = snapshot.val()
    if (bulb_03_status["BULB_03"] == "ON")
      document.getElementById("d03_img").src = "./img/light_bulb_on.png"
    else
      document.getElementById("d03_img").src = "./img/light_bulb_off.png"
  }
  else
    console.log("No data available!")
})

firebase.database().ref("/TT_IoT").get().then((snapshot) => {
  if(snapshot.exists()){
    console.log(snapshot.val())

    var bulb_04_status = snapshot.val()
    if (bulb_04_status["BULB_04"] == "ON")
      document.getElementById("d04_img").src = "./img/light_bulb_on.png"
    else
      document.getElementById("d04_img").src = "./img/light_bulb_off.png"
  }
  else
    console.log("No data available!")
})



//Den 01-------------------------------------------------------
var d01_on = document.getElementById("d01_on");
var d01_off = document.getElementById("d01_off");

d01_on.onclick = function(){
    console.log("On");
    document.getElementById("d01_img").src = "./img/light_bulb_on.png"
    
    firebase.database().ref("/TT_IoT").update({
    "BULB_01": "ON"
  })
}

d01_off.onclick = function(){
	document.getElementById("d01_img").src = "./img/light_bulb_off.png"
	
  firebase.database().ref("/TT_IoT").update({
		"BULB_01": "OFF"
	})
}
//
var d02_on = document.getElementById("d02_on");
var d02_off = document.getElementById("d02_off");

d02_on.onclick = function(){
    console.log("On");
    document.getElementById("d02_img").src = "./img/light_bulb_on.png"
    
    firebase.database().ref("/TT_IoT").update({
    "BULB_02": "ON"
  })
}

d02_off.onclick = function(){
	document.getElementById("d02_img").src = "./img/light_bulb_off.png"
	
  firebase.database().ref("/TT_IoT").update({
		"BULB_02": "OFF"
	})
}

var d03_on = document.getElementById("d03_on");
var d03_off = document.getElementById("d03_off");

d03_on.onclick = function(){
    console.log("On");
    document.getElementById("d03_img").src = "./img/light_bulb_on.png"
    
    firebase.database().ref("/TT_IoT").update({
    "BULB_03": "ON"
  })
}

d03_off.onclick = function(){
	document.getElementById("d03_img").src = "./img/light_bulb_off.png"
	
  firebase.database().ref("/TT_IoT").update({
		"BULB_03": "OFF"
	})
}
//
var d04_on = document.getElementById("d04_on");
var d04_off = document.getElementById("d04_off");

d04_on.onclick = function(){
    console.log("On");
    document.getElementById("d04_img").src = "./img/light_bulb_on.png"
    
    firebase.database().ref("/TT_IoT").update({
    "BULB_04": "ON"
  })
}

d04_off.onclick = function(){
	document.getElementById("d04_img").src = "./img/light_bulb_off.png"
	
  firebase.database().ref("/TT_IoT").update({
		"BULB_04": "OFF"
	})
}



