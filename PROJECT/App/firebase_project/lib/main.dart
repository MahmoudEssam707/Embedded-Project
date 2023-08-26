// ignore_for_file: prefer_const_constructors

import 'package:firebase_project/firebase/Auth.dart';
import 'package:firebase_project/firebase/userProfile.dart';
import 'package:firebase_project/home/DoorControl.dart';
import 'package:firebase_project/firebase/firebase_options.dart';
import 'package:firebase_project/home/SensorReads.dart';
import 'package:firebase_project/home/home.dart';
import 'package:firebase_project/firebase/login.dart';
import 'package:firebase_project/firebase/signup.dart';
import 'package:flutter/material.dart';
import 'package:firebase_core/firebase_core.dart';

void main() async {
  WidgetsFlutterBinding.ensureInitialized();
  await Firebase.initializeApp(
    options: DefaultFirebaseOptions.currentPlatform,
  );
  runApp(MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      debugShowCheckedModeBanner: false,
      routes: {
        '/': (context) => Auth(),
        'SignUpScreen': (context) => SignUpScreen(),
        'LoginScreen': (context) => LoginScreen(),
        'HomeScreen': (context) => HomeScreen(),
        'DoorControl': (context) => ServoControl(),
        'SensorReads': (context) => SensorsReads(),
        'UserData': (context) => UserProfile(),
      },
    );
  }
}
