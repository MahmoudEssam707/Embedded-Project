import 'package:cloud_firestore/cloud_firestore.dart';
import 'package:firebase_auth/firebase_auth.dart';
import 'package:flutter/material.dart';
import 'package:google_fonts/google_fonts.dart';

class SideBar extends StatefulWidget {
  const SideBar({super.key});

  @override
  State<SideBar> createState() => _SideBarState();
}

class _SideBarState extends State<SideBar> {
  final user = FirebaseAuth.instance.currentUser;
  String firstName = '';
  String lastName = '';
  String Email = '';
  @override
  void initState() {
    super.initState();
    retrieveUserData();
  }

  Future<void> retrieveUserData() async {
    try {
      if (user != null) {
        DocumentSnapshot userSnapshot = await FirebaseFirestore.instance
            .collection('users')
            .doc(user!.uid)
            .get();

        if (userSnapshot.exists) {
          Map<String, dynamic> userData =
              userSnapshot.data() as Map<String, dynamic>;
          setState(() {
            firstName = userData['first_name'];
            lastName = userData['last_name'];
            Email = userData['email'];
          });
        }
      }
    } catch (e) {
      print("Error during user data retrieval: $e");
    }
  }

  @override
  Widget build(BuildContext context) {
    return Drawer(
      child: ListView(
        children: [
          UserAccountsDrawerHeader(
            decoration: BoxDecoration(color: Colors.teal),
            accountName: Text(
              "$firstName $lastName",
              style: GoogleFonts.robotoCondensed(fontSize: 30),
            ),
            accountEmail: Text(
              "$Email",
              style: GoogleFonts.robotoCondensed(fontSize: 20),
            ),
          ),
          SizedBox(height: 10),
          ListTile(
            leading: Icon(Icons.sensor_door),
            title: Text(
              "Control Door",
              style: GoogleFonts.robotoCondensed(fontSize: 20),
            ),
            onTap: () {
              Navigator.of(context).pushReplacementNamed("DoorControl");
            },
          ),
          SizedBox(height: 10),
          ListTile(
            leading: Icon(Icons.sensors_sharp),
            title: Text(
              "Sensors of home",
              style: GoogleFonts.robotoCondensed(fontSize: 20),
            ),
            onTap: () {
              Navigator.of(context).pushReplacementNamed("SensorReads");
            },
          ),
          SizedBox(height: 10),
          ListTile(
            leading: Icon(Icons.person),
            title: Text(
              "Information",
              style: GoogleFonts.robotoCondensed(fontSize: 20),
            ),
            onTap: () {
              Navigator.of(context).pushReplacementNamed("UserData");
            },
          )
        ],
      ),
    );
  }
}
