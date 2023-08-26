// ignore_for_file: use_key_in_widget_constructors, library_private_types_in_public_api, avoid_print, prefer_const_constructors

import 'package:firebase_project/services/notification.dart';
import 'package:firebase_project/services/sideBar.dart';
import 'package:flutter/material.dart';
import 'package:firebase_auth/firebase_auth.dart';
import 'package:flutter_local_notifications/flutter_local_notifications.dart';
import 'package:google_fonts/google_fonts.dart';

class HomeScreen extends StatefulWidget {
  @override
  _HomeScreenState createState() => _HomeScreenState();
}

class _HomeScreenState extends State<HomeScreen> {
  FlutterLocalNotificationsPlugin flutterLocalNotificationsPlugin =
      FlutterLocalNotificationsPlugin();
  @override
  void initState() {
    super.initState();
    Noti.initialize(flutterLocalNotificationsPlugin);
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      drawer: SideBar(),
      appBar: AppBar(
        backgroundColor: Colors.teal,
        title: Text(
          "Home Screen",
          style: GoogleFonts.robotoCondensed(fontWeight: FontWeight.bold),
        ),
        actions: [
          IconButton(
              onPressed: () {
                FirebaseAuth.instance.signOut();
                Navigator.of(context).pushReplacementNamed('LoginScreen');
              },
              icon: Icon(Icons.logout))
        ],
      ),
      body: Center(
        child: SingleChildScrollView(
          child: Column(
            mainAxisAlignment: MainAxisAlignment.center,
            children: [
              SizedBox(
                height: 20,
              ),
              Container(
                decoration: BoxDecoration(
                    borderRadius: BorderRadius.circular(20),
                    color: Colors.white),
                child: Padding(
                  padding: const EdgeInsets.all(20.0),
                  child: Image(
                    image: AssetImage('images/logo.png'),
                    fit: BoxFit.fitWidth,
                  ),
                ),
              ),
              SizedBox(height: 20),
              Padding(
                padding: const EdgeInsets.symmetric(horizontal: 30),
                child: Container(
                  padding: EdgeInsets.all(15),
                  decoration: BoxDecoration(
                      color: Colors.grey[100],
                      borderRadius: BorderRadius.circular(10)),
                  child: Text(
                    "Hello, How are you?\nLet me start to tell you what's is this application do\n1-There exist Controlling your door in sidebar\n2-There's Sesnor page to check if trouble has happened to your home\n3-Your data and if you want to change current password\nHope for you Great journey! dev.Mahmoud Essam",
                    style: GoogleFonts.robotoCondensed(
                        color: Colors.teal,
                        fontWeight: FontWeight.bold,
                        fontSize: 20),
                  ),
                ),
              ),
              SizedBox(height: 10),
              ElevatedButton(
                style: ElevatedButton.styleFrom(
                  backgroundColor: Colors.teal,
                  foregroundColor: Colors.white,
                  shape: RoundedRectangleBorder(
                    borderRadius: BorderRadius.circular(10),
                  ),
                ),
                onPressed: () {
                  Noti.showBigTextNotification(
                      text: "Who are we?",
                      body:
                          "Hello i'm Mahmoud Essam, the developer of this app, With help of my team project",
                      fln: flutterLocalNotificationsPlugin);
                },
                child: Padding(
                  padding: const EdgeInsets.all(10.0),
                  child: Text(
                    "Press Here",
                    style: GoogleFonts.robotoCondensed(fontSize: 15),
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
