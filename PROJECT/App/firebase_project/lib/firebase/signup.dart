// ignore_for_file: prefer_const_constructors, non_constant_identifier_names, avoid_print

import 'package:firebase_auth/firebase_auth.dart';
import 'package:flutter/material.dart';
import 'package:google_fonts/google_fonts.dart';
import 'package:cloud_firestore/cloud_firestore.dart';

class SignUpScreen extends StatefulWidget {
  const SignUpScreen({super.key});

  @override
  State<SignUpScreen> createState() => SignUpScreenState();
}

class SignUpScreenState extends State<SignUpScreen> {
  bool isPasswordVisible = false;
  final _EmailController = TextEditingController();
  final _PasswordController = TextEditingController();
  final _ConfirmPasswordController = TextEditingController();
  final _FirstNameController = TextEditingController();
  final _LastNameController = TextEditingController();

  @override
  void dispose() {
    super.dispose();
    _EmailController.dispose();
    _PasswordController.dispose();
    _ConfirmPasswordController.dispose();
    _FirstNameController.dispose();
    _LastNameController.dispose();
  }

  bool PasswordCorrect() {
    return _PasswordController.text.trim() ==
        _ConfirmPasswordController.text.trim();
  }

  void SignIn() {
    Navigator.of(context).pushReplacementNamed('LoginScreen');
  }

  Future SignUp() async {
    if (PasswordCorrect()) {
      try {
        final userCredential =
            await FirebaseAuth.instance.createUserWithEmailAndPassword(
          email: _EmailController.text.trim(),
          password: _PasswordController.text.trim(),
        );
        // Store user's first and last name in Firestore
        await FirebaseFirestore.instance
            .collection('users')
            .doc(userCredential.user?.uid)
            .set({
          'email': _EmailController.text.trim(),
          'password': _PasswordController.text.trim(),
          'first_name': _FirstNameController.text.trim(),
          'last_name': _LastNameController.text.trim(),
        });
        // ignore: use_build_context_synchronously
        Navigator.of(context).popAndPushNamed("/");
      } catch (e) {
        // Handle any errors during sign-up
        print("Error during sign-up: $e");
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
                SizedBox(height: 20),
                Text(
                  "Sign Up",
                  style: GoogleFonts.robotoCondensed(
                      fontSize: 40,
                      fontWeight: FontWeight.bold,
                      color: Colors.teal),
                ),
                Text("Hello new one!",
                    style: GoogleFonts.robotoCondensed(
                        fontSize: 20, color: Colors.teal)),
                SizedBox(height: 20),
                Row(
                  children: [
                    Expanded(
                      child: Padding(
                        padding: const EdgeInsets.symmetric(horizontal: 25),
                        child: Container(
                          decoration: BoxDecoration(
                              color: Colors.white,
                              borderRadius: BorderRadius.circular(12)),
                          child: TextField(
                            controller: _FirstNameController,
                            decoration: InputDecoration(
                              border: InputBorder.none,
                              labelText: "First Name",
                              labelStyle: TextStyle(
                                  color: Colors.grey,
                                  fontWeight: FontWeight.bold),
                              prefixIcon: Icon(
                                Icons.person,
                                color: Colors.grey[700],
                              ),
                            ),
                          ),
                        ),
                      ),
                    ),
                    Expanded(
                      child: Padding(
                        padding: const EdgeInsets.symmetric(horizontal: 25),
                        child: Container(
                          decoration: BoxDecoration(
                              color: Colors.white,
                              borderRadius: BorderRadius.circular(12)),
                          child: TextField(
                            controller: _LastNameController,
                            decoration: InputDecoration(
                              border: InputBorder.none,
                              labelText: "Last Name",
                              labelStyle: TextStyle(
                                  color: Colors.grey,
                                  fontWeight: FontWeight.bold),
                              prefixIcon: Icon(
                                Icons.person,
                                color: Colors.grey[700],
                              ),
                            ),
                          ),
                        ),
                      ),
                    ),
                  ],
                ),
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
                        controller: _ConfirmPasswordController,
                        obscureText: !isPasswordVisible,
                        decoration: InputDecoration(
                          border: InputBorder.none,
                          labelText: "Confirm Password",
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
                SizedBox(height: 20),
                Padding(
                  padding: const EdgeInsets.symmetric(horizontal: 25.0),
                  child: GestureDetector(
                    onTap: SignUp,
                    child: Container(
                      padding: EdgeInsets.all(16),
                      decoration: BoxDecoration(
                          color: Colors.teal,
                          borderRadius: BorderRadius.circular(15)),
                      child: Center(
                        child: Text(
                          "Sign up",
                          style: GoogleFonts.robotoCondensed(
                              color: Colors.white,
                              fontWeight: FontWeight.bold,
                              fontSize: 20),
                        ),
                      ),
                    ),
                  ),
                ),
                SizedBox(height: 10),
                Row(
                  mainAxisAlignment: MainAxisAlignment.center,
                  children: [
                    Text("already a member ?",
                        style: GoogleFonts.robotoCondensed()),
                    GestureDetector(
                      onTap: SignIn,
                      child: Text(
                        " Sign in Here!",
                        style: GoogleFonts.robotoCondensed(
                            fontWeight: FontWeight.bold,
                            color: Colors.green[600]),
                      ),
                    ),
                    SizedBox(height: 20)
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
