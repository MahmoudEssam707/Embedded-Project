import 'package:firebase_project/services/notification.dart';
import 'package:flutter/material.dart';
import 'package:firebase_auth/firebase_auth.dart';
import 'package:firebase_database/firebase_database.dart';
import 'package:flutter_local_notifications/flutter_local_notifications.dart';
import 'package:google_fonts/google_fonts.dart';

class SensorsReads extends StatefulWidget {
  const SensorsReads({super.key});

  @override
  State<SensorsReads> createState() => _SensorsReadsState();
}

class _SensorsReadsState extends State<SensorsReads> {
  FlutterLocalNotificationsPlugin flutterLocalNotificationsPlugin =
      FlutterLocalNotificationsPlugin();
  late DatabaseReference databaseReference;
  int flameStatus = 0;
  int gasStatus = 0;
  int waterStatus = 0;
  int motionStatus = 0;
  @override
  void initState() {
    super.initState();
    databaseReference = FirebaseDatabase.instance
        .ref()
        .child("UsersData/${FirebaseAuth.instance.currentUser!.uid}/Sensors");
    // Listen for changes in sensor data
    databaseReference.onValue.listen((event) {
      var data = event.snapshot.value;
      if (data != null && data is Map) {
        setState(() {
          flameStatus = data['Flame'] ?? 0;
          gasStatus = data['Gas'] ?? 0;
          waterStatus = data['Water'] ?? 0;
          motionStatus = data['Motion'] ?? 0;
        });
      } else {
        print("Data is null or not of type Map.");
      }
      Noti.initialize(flutterLocalNotificationsPlugin);
      if (motionStatus == 1) {
        Noti.showBigTextNotification(
            text: "Motion!",
            body: "There's someone at home",
            fln: flutterLocalNotificationsPlugin);
      }
      if (flameStatus < 30) {
        Noti.showBigTextNotification(
            text: "FLAME!!",
            body: "There's flame catches home",
            fln: flutterLocalNotificationsPlugin);
      }
      if (gasStatus > 50) {
        Noti.showBigTextNotification(
            text: "GAS!!",
            body: "Close the Source of it!",
            fln: flutterLocalNotificationsPlugin);
      }
      if (waterStatus > 30) {
        Noti.showBigTextNotification(
            text: "Water!",
            body: "Close the engine",
            fln: flutterLocalNotificationsPlugin);
      }
    });
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        backgroundColor: Colors.teal,
        leading: IconButton(
            icon: Icon(Icons.arrow_back),
            onPressed: () {
              Navigator.of(context).pushReplacementNamed('HomeScreen');
            }),
        title: Text(
          "Sensors",
          style: GoogleFonts.robotoCondensed(
              color: Colors.white, fontWeight: FontWeight.bold),
        ),
      ),
      body: Center(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children: [
            SizedBox(height: 10),
            Expanded(
              child: Center(
                child: Padding(
                  padding: const EdgeInsets.symmetric(horizontal: 30.0),
                  child: Container(
                    width: double.infinity,
                    decoration: BoxDecoration(
                      borderRadius: BorderRadius.circular(20),
                      color: Colors.green[100],
                    ),
                    child: Column(
                      mainAxisAlignment: MainAxisAlignment.center,
                      children: [
                        Icon(
                          Icons.water,
                          size: 100,
                          color:
                              waterStatus > 30 ? Colors.red : Colors.teal[800],
                        ), // Adjust the size of the icon as needed
                        Text(
                          "Water: $waterStatus",
                          style: GoogleFonts.robotoCondensed(
                            color: waterStatus > 30
                                ? Colors.red
                                : Colors.teal[800],
                            fontWeight: FontWeight.bold,
                            fontSize: 35,
                          ),
                        ),
                      ],
                    ),
                  ),
                ),
              ),
            ),
            SizedBox(
              height: 10,
            ),
            Expanded(
              child: Center(
                child: Padding(
                  padding: const EdgeInsets.symmetric(horizontal: 30.0),
                  child: Container(
                    width: double.infinity,
                    decoration: BoxDecoration(
                      borderRadius: BorderRadius.circular(20),
                      color: Colors.green[100],
                    ),
                    child: Column(
                      mainAxisAlignment: MainAxisAlignment.center,
                      children: [
                        Icon(
                          Icons.fire_extinguisher,
                          size: 100,
                          color:
                              flameStatus < 30 ? Colors.red : Colors.teal[800],
                        ), // Adjust the size of the icon as needed
                        Text(
                          "Fire Sensor: $flameStatus",
                          style: GoogleFonts.robotoCondensed(
                            color: flameStatus < 30
                                ? Colors.red
                                : Colors.teal[800],
                            fontWeight: FontWeight.bold,
                            fontSize: 35,
                          ),
                        ),
                      ],
                    ),
                  ),
                ),
              ),
            ),
            SizedBox(
              height: 10,
            ),
            Expanded(
              child: Center(
                child: Padding(
                  padding: const EdgeInsets.symmetric(horizontal: 30.0),
                  child: Container(
                    width: double.infinity,
                    decoration: BoxDecoration(
                      borderRadius: BorderRadius.circular(20),
                      color: Colors.green[100],
                    ),
                    child: Column(
                      mainAxisAlignment: MainAxisAlignment.center,
                      children: [
                        Icon(
                          Icons.gas_meter,
                          size: 100,
                          color: gasStatus > 50 ? Colors.red : Colors.teal[800],
                        ), // Adjust the size of the icon as needed
                        Text(
                          "Gas Sensor: $gasStatus",
                          style: GoogleFonts.robotoCondensed(
                            color:
                                gasStatus > 50 ? Colors.red : Colors.teal[800],
                            fontWeight: FontWeight.bold,
                            fontSize: 35,
                          ),
                        ),
                      ],
                    ),
                  ),
                ),
              ),
            ),
            SizedBox(
              height: 10,
            ),
            Expanded(
              child: Center(
                child: Padding(
                  padding: const EdgeInsets.symmetric(horizontal: 30.0),
                  child: Container(
                    width: double.infinity,
                    decoration: BoxDecoration(
                      borderRadius: BorderRadius.circular(20),
                      color: Colors.green[100],
                    ),
                    child: Column(
                      mainAxisAlignment: MainAxisAlignment.center,
                      children: [
                        Icon(
                          Icons.person,
                          size: 100,
                          color:
                              motionStatus == 1 ? Colors.red : Colors.teal[800],
                        ), // Adjust the size of the icon as needed
                        Text(
                          "Motion Detection: $motionStatus",
                          style: GoogleFonts.robotoCondensed(
                            color: motionStatus == 1
                                ? Colors.red
                                : Colors.teal[800],
                            fontWeight: FontWeight.bold,
                            fontSize: 35,
                          ),
                        ),
                      ],
                    ),
                  ),
                ),
              ),
            ),
            SizedBox(
              height: 10,
            )
          ],
        ),
      ),
    );
  }
}
