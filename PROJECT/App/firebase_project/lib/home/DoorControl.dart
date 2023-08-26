// ignore_for_file: prefer_const_constructors, file_names, use_key_in_widget_constructors, prefer_const_declarations, unused_element, unused_import

import 'package:firebase_project/services/notification.dart';
import 'package:flutter/material.dart';
import 'package:flutter_local_notifications/flutter_local_notifications.dart';
import 'package:google_fonts/google_fonts.dart';
import 'package:firebase_database/firebase_database.dart';
import 'package:firebase_core/firebase_core.dart';
import 'package:firebase_auth/firebase_auth.dart';

FlutterLocalNotificationsPlugin flutterLocalNotificationsPlugin =
    FlutterLocalNotificationsPlugin();

class ServoControl extends StatefulWidget {
  const ServoControl({Key? key}) : super(key: key);

  @override
  State<ServoControl> createState() => _ServoControlState();
}

class _ServoControlState extends State<ServoControl> {
  double servo = 172;
  late DatabaseReference databaseReference;

  @override
  void initState() {
    super.initState();
    Noti.initialize(flutterLocalNotificationsPlugin);
    databaseReference = FirebaseDatabase.instance.ref().child(
        "UsersData/${FirebaseAuth.instance.currentUser!.uid}/Sensors/Door");
  }

  void updateServoValue(double newValue) {
    setState(() {
      servo = newValue.roundToDouble();
      databaseReference.set({'door_angle': servo});
      if (servo == 130) {
        Noti.showBigTextNotification(
            text: "Door Fully Opened!",
            body: "Sir your door totally opened, Make sure of theifs",
            fln: flutterLocalNotificationsPlugin);
      } else if (servo == 172) {
        Noti.showBigTextNotification(
            text: "Door Closed",
            body: "Your home is under safe now",
            fln: flutterLocalNotificationsPlugin);
      }
    });
  }

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      debugShowCheckedModeBanner: false,
      home: Scaffold(
        appBar: AppBar(
          backgroundColor: Colors.teal,
          leading: IconButton(
            icon: Icon(Icons.arrow_back),
            onPressed: () {
              Navigator.of(context).pushReplacementNamed('HomeScreen');
            },
          ),
          title: Text(
            "Controlling Door",
            style: GoogleFonts.robotoCondensed(fontWeight: FontWeight.bold),
          ),
        ),
        body: Center(
          child: Column(
            mainAxisAlignment: MainAxisAlignment.center,
            children: [
              SizedBox(
                height: 10,
              ),
              Expanded(
                child: Padding(
                  padding: const EdgeInsets.symmetric(horizontal: 10.0),
                  child: Container(
                    decoration: BoxDecoration(
                      borderRadius: BorderRadius.circular(20),
                      color: Colors.green[100],
                    ),
                    width: double.infinity,
                    child: Column(
                      mainAxisAlignment: MainAxisAlignment.center,
                      children: [
                        SizedBox(height: 10),
                        Icon(
                          Icons.door_front_door,
                          size: 50,
                          color: Colors.teal[800],
                        ),
                        Container(
                          padding: EdgeInsets.all(15),
                          child: Text(
                            "Sensor of door",
                            style: GoogleFonts.robotoCondensed(
                              color: Colors.teal[800],
                              fontWeight: FontWeight.bold,
                              fontSize: 35,
                            ),
                          ),
                        ),
                      ],
                    ),
                  ),
                ),
              ),
              SizedBox(height: 20),
              Padding(
                padding: const EdgeInsets.symmetric(horizontal: 10.0),
                child: Container(
                  decoration: BoxDecoration(
                    borderRadius: BorderRadius.circular(20),
                    color: Colors.green[100],
                  ),
                  padding: EdgeInsets.all(30),
                  width: double.infinity,
                  child: Slider(
                    min: 130,
                    max: 172,
                    value: servo,
                    onChanged: updateServoValue,
                    activeColor: Colors.teal,
                    inactiveColor: Colors.tealAccent[300],
                  ),
                ),
              ),
              SizedBox(height: 20),
              Expanded(
                child: Padding(
                  padding: const EdgeInsets.symmetric(horizontal: 10.0),
                  child: Container(
                    decoration: BoxDecoration(
                      borderRadius: BorderRadius.circular(20),
                      color: Colors.green[100],
                    ),
                    width: double.infinity,
                    child: Column(
                      mainAxisAlignment: MainAxisAlignment.center,
                      children: [
                        SizedBox(height: 10),
                        Container(
                          padding: EdgeInsets.all(15),
                          child: Text(
                            "Current angle: $servo",
                            style: GoogleFonts.robotoCondensed(
                              color: Colors.teal[800],
                              fontWeight: FontWeight.bold,
                              fontSize: 35,
                            ),
                          ),
                        ),
                      ],
                    ),
                  ),
                ),
              ),
              SizedBox(
                height: 20,
              ),
            ],
          ),
        ),
      ),
    );
  }
}
