// File generated by FlutterFire CLI.
// ignore_for_file: lines_longer_than_80_chars, avoid_classes_with_only_static_members
import 'package:firebase_core/firebase_core.dart' show FirebaseOptions;
import 'package:flutter/foundation.dart'
    show defaultTargetPlatform, kIsWeb, TargetPlatform;

/// Default [FirebaseOptions] for use with your Firebase apps.
///
/// Example:
/// ```dart
/// import 'firebase_options.dart';
/// // ...
/// await Firebase.initializeApp(
///   options: DefaultFirebaseOptions.currentPlatform,
/// );
/// ```
class DefaultFirebaseOptions {
  static FirebaseOptions get currentPlatform {
    if (kIsWeb) {
      return web;
    }
    switch (defaultTargetPlatform) {
      case TargetPlatform.android:
        return android;
      case TargetPlatform.iOS:
        return ios;
      case TargetPlatform.macOS:
        throw UnsupportedError(
          'DefaultFirebaseOptions have not been configured for macos - '
          'you can reconfigure this by running the FlutterFire CLI again.',
        );
      case TargetPlatform.windows:
        throw UnsupportedError(
          'DefaultFirebaseOptions have not been configured for windows - '
          'you can reconfigure this by running the FlutterFire CLI again.',
        );
      case TargetPlatform.linux:
        throw UnsupportedError(
          'DefaultFirebaseOptions have not been configured for linux - '
          'you can reconfigure this by running the FlutterFire CLI again.',
        );
      default:
        throw UnsupportedError(
          'DefaultFirebaseOptions are not supported for this platform.',
        );
    }
  }

  static const FirebaseOptions web = FirebaseOptions(
    apiKey: 'AIzaSyAB8Ne5FKZ_5P6YWz4YY8TpowIKtWDLn1Q',
    appId: '1:679777121175:web:f2ee3d22e54bdc3f26cad2',
    messagingSenderId: '679777121175',
    projectId: 'fir-visualstudio-d089e',
    authDomain: 'fir-visualstudio-d089e.firebaseapp.com',
    databaseURL:
        'https://fir-visualstudio-d089e-default-rtdb.firebaseio.com/', // IMPORTANT!
    storageBucket: 'fir-visualstudio-d089e.appspot.com',
  );

  static const FirebaseOptions android = FirebaseOptions(
    apiKey: 'AIzaSyDADshUI7Rjw6jynScYy5-6RYRgbZrs9mk',
    appId: '1:679777121175:android:e1e915b53a579c5a26cad2',
    messagingSenderId: '679777121175',
    projectId: 'fir-visualstudio-d089e',
    databaseURL: 'https://fir-visualstudio-d089e-default-rtdb.firebaseio.com/',
    storageBucket: 'fir-visualstudio-d089e.appspot.com',
  );

  static const FirebaseOptions ios = FirebaseOptions(
    apiKey: 'AIzaSyAOsdFM4t33LU2rzzEOLM6yatahKOEsh_M',
    appId: '1:679777121175:ios:f94bbd81793c706b26cad2',
    messagingSenderId: '679777121175',
    projectId: 'fir-visualstudio-d089e',
    databaseURL: 'https://fir-visualstudio-d089e-default-rtdb.firebaseio.com/',
    storageBucket: 'fir-visualstudio-d089e.appspot.com',
    iosClientId:
        '679777121175-h62ei9ir66t518r44bgcd6cfqg3fu20u.apps.googleusercontent.com',
    iosBundleId: 'com.example.firebaseProject',
  );
}
