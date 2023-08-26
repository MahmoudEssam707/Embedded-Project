// ignore_for_file: prefer_const_constructors,use_build_context_synchronously, use_key_in_widget_constructors, non_constant_identifier_names, unused_field, unnecessary_null_comparison

import 'package:firebase_auth/firebase_auth.dart';
import 'package:flutter/material.dart';
import 'package:fluttertoast/fluttertoast.dart';
import 'package:google_fonts/google_fonts.dart';
import 'package:cloud_firestore/cloud_firestore.dart';

class LoginScreen extends StatefulWidget {
  @override
  State<LoginScreen> createState() => _LoginScreenState();
}

class _LoginScreenState extends State<LoginScreen> {
  bool isPasswordVisible = false; // Added state for password visibility
  final _EmailController = TextEditingController();
  final _PasswordController = TextEditingController();
  @override
  void dispose() {
    super.dispose();
    _EmailController.dispose();
    _PasswordController.dispose();
  }

  void SignUp() {
    Navigator.of(context).pushReplacementNamed('SignUpScreen');
  }

  Future<void> signIn() async {
    try {
      final userCredential =
          await FirebaseAuth.instance.signInWithEmailAndPassword(
        email: _EmailController.text.trim(),
        password: _PasswordController.text.trim(),
      );
      String uid = userCredential.user!.uid;
      if (uid != null) {
        DocumentSnapshot userSnapshot =
            await FirebaseFirestore.instance.collection('users').doc(uid).get();

        if (userSnapshot.exists) {
          Map<String, dynamic> userData =
              userSnapshot.data() as Map<String, dynamic>;
          String firstName = userData['first_name'];
          String lastName = userData['last_name'];

          Fluttertoast.showToast(
            msg: 'Hello $firstName $lastName!',
            toastLength: Toast.LENGTH_LONG,
            gravity: ToastGravity.BOTTOM,
            backgroundColor: Colors.red,
            textColor: Colors.white,
          );
          // Navigate to the main page after successful sign-in
          Navigator.of(context).pushReplacementNamed('HomeScreen');
        }
      }
    } catch (error) {
      if (error is FirebaseAuthException) {
        if (error.code == 'user-not-found') {
          Fluttertoast.showToast(
            msg:
                'There is no user record corresponding to this identifier.\nThe user may have been deleted.',
            toastLength: Toast.LENGTH_LONG,
            gravity: ToastGravity.BOTTOM,
            backgroundColor: Colors.red,
            textColor: Colors.white,
          );
        } else {
          Fluttertoast.showToast(
            msg: 'Something went wrong. Please try again.',
            toastLength: Toast.LENGTH_SHORT,
            gravity: ToastGravity.BOTTOM,
            backgroundColor: Colors.grey[700],
            textColor: Colors.white,
          );
        }
      }
    }
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      backgroundColor: Colors.grey[400],
      body: SafeArea(
        child: Center(
          child: SingleChildScrollView(
            child: Column(
              mainAxisAlignment: MainAxisAlignment.center,
              children: [
                // image
                Container(
                  decoration: BoxDecoration(
                      borderRadius: BorderRadius.circular(20),
                      color: Colors.white),
                  child: Padding(
                    padding: const EdgeInsets.all(20.0),
                    child: Image(
                      image: AssetImage('images/logo.png'),
                      fit: BoxFit.fitWidth,
                      width: 200,
                      height: 200,
                    ),
                  ),
                ),
                SizedBox(height: 30),
                // title
                Text(
                  "Sign In",
                  style: GoogleFonts.robotoCondensed(
                      fontSize: 40,
                      fontWeight: FontWeight.bold,
                      color: Colors.teal),
                ),
                // subtitle
                Text(
                  "Welcome Back!",
                  style: GoogleFonts.robotoCondensed(
                      fontSize: 20, color: Colors.teal),
                ),
                // email
                SizedBox(height: 55),
                Padding(
                  padding: const EdgeInsets.symmetric(horizontal: 25),
                  child: Container(
                    decoration: BoxDecoration(
                        color: Colors.white,
                        borderRadius: BorderRadius.circular(12)),
                    child: Padding(
                      padding: const EdgeInsets.symmetric(horizontal: 20.0),
                      child: TextField(
                        controller: _EmailController,
                        decoration: InputDecoration(
                          border: InputBorder.none,
                          labelText: "Email",
                          labelStyle: TextStyle(
                              color: Colors.grey, fontWeight: FontWeight.bold),
                          prefixIcon: Icon(
                            Icons.email,
                            color: Colors.grey[700],
                          ),
                        ),
                      ),
                    ),
                  ),
                ),
                // password
                SizedBox(height: 20),
                Padding(
                  padding: const EdgeInsets.symmetric(horizontal: 25),
                  child: Container(
                    decoration: BoxDecoration(
                        color: Colors.white,
                        borderRadius: BorderRadius.circular(12)),
                    child: Padding(
                      padding: const EdgeInsets.symmetric(horizontal: 20.0),
                      child: TextField(
                        controller: _PasswordController,
                        obscureText: !isPasswordVisible,
                        decoration: InputDecoration(
                          border: InputBorder.none,
                          labelText: "Password",
                          labelStyle: TextStyle(
                              color: Colors.grey, fontWeight: FontWeight.bold),
                          prefixIcon: Icon(
                            Icons.password,
                            color: Colors.grey[700],
                          ),
                          suffixIcon: IconButton(
                            icon: Icon(
                              isPasswordVisible
                                  ? Icons.visibility
                                  : Icons.visibility_off,
                              color: Colors.grey[700],
                            ),
                            onPressed: () {
                              setState(() {
                                isPasswordVisible = !isPasswordVisible;
                              });
                            },
                          ),
                        ),
                      ),
                    ),
                  ),
                ),
                // sign in button
                SizedBox(height: 20),
                Padding(
                  padding: const EdgeInsets.symmetric(horizontal: 25.0),
                  child: GestureDetector(
                    onTap: signIn,
                    child: Container(
                        padding: EdgeInsets.all(16),
                        decoration: BoxDecoration(
                            color: Colors.teal,
                            borderRadius: BorderRadius.circular(15)),
                        child: Center(
                            child: Text(
                          "Sign in",
                          style: GoogleFonts.robotoCondensed(
                              color: Colors.white,
                              fontWeight: FontWeight.bold,
                              fontSize: 20),
                        ))),
                  ),
                ),
                // signup button
                SizedBox(height: 10),
                Row(
                  mainAxisAlignment: MainAxisAlignment.center,
                  children: [
                    Text("Not member yet ?",
                        style: GoogleFonts.robotoCondensed()),
                    GestureDetector(
                      onTap: SignUp,
                      child: Text(
                        " Sign up Now!",
                        style: GoogleFonts.robotoCondensed(
                            fontWeight: FontWeight.bold,
                            color: Colors.green[600]),
                      ),
                    )
                  ],
                )
              ],
            ),
          ),
        ),
      ),
    );
  }
}
