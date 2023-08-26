import 'package:flutter_local_notifications/flutter_local_notifications.dart';

class Noti {
  static Future initialize(
      FlutterLocalNotificationsPlugin flutterLocalNotificationsPlugin) async {
    var androidInitialize =
        const AndroidInitializationSettings('mipmap/ic_launcher');
    var initializationsSettings =
        InitializationSettings(android: androidInitialize);
    await flutterLocalNotificationsPlugin.initialize(initializationsSettings);
  }

  static Future<void> showBigTextNotification({
    int id = 0,
    required String text,
    required String body,
    String? payload,
    required FlutterLocalNotificationsPlugin fln,
  }) async {
    const AndroidNotificationDetails androidPlatformChannelSpecifics =
        AndroidNotificationDetails(
      'aloo', // Replace with your channel ID
      'Your Channel Name', // Replace with your channel name
      channelDescription: 'Your_Channel_Description',
      playSound: true,
      importance: Importance.high,
      priority: Priority.high,
    );

    const NotificationDetails platformChannelSpecifics =
        NotificationDetails(android: androidPlatformChannelSpecifics);
    await fln.show(
      id,
      text,
      body,
      platformChannelSpecifics,
      payload: payload,
    );
  }
}
