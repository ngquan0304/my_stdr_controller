#include <math.h>
#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
//node to send Twist commands to the Simple 2-Dimensional Robot Simulator via cmd_vel
int main(int argc, char **argv)
{
      ros::init(argc, argv, "stdr_commander");
      ros::NodeHandle n; // two lines to create a publisher object that can talk to ROS
      ros::Publisher twist_commander = n.advertise<geometry_msgs::Twist>("/robot0/cmd_vel", 1);
      //some "magic numbers"
      double sample_dt = 0.01;  //specify a sample period of 10ms
      double speed = 1.0;       // 1m/s speed command
      double yaw_rate = 1.0;    // 1 rad/sec yaw rate command
      double time_3_sec = 3.0;  // should move 3 meters or 1.5 rad in 3 seconds

      geometry_msgs::Twist twist_cmd; //this is the message type required to send twist commands to STDR
      // start with all zeros in the command message; should be the case by default, but just to be safe..
      twist_cmd.linear.x = 0.0;
      twist_cmd.linear.y = 0.0;
      twist_cmd.linear.z = 0.0;
      twist_cmd.angular.x = 0.0;
      twist_cmd.angular.y = 0.0;
      twist_cmd.angular.z = 0.0;

      ros::Rate loop_timer(1 / sample_dt); //create a ros object from the ros “Rate” class; set 100Hz rate
      double timer = 0.0;
      //start sending some zero-velocity commands, just to warm up communications with STDR
      for (int i = 0; i < 10; i++)
      {
            twist_commander.publish(twist_cmd);
            loop_timer.sleep();
      }

      // Running straight
      twist_cmd.linear.x = speed; //command to move forward
      while (timer < 3.5)
      {
            ROS_INFO_STREAM("Straight");
            twist_commander.publish(twist_cmd);
            timer += sample_dt;
            loop_timer.sleep();
      }

      // Rotate left
      twist_cmd.linear.x = 0;
      twist_cmd.angular.z = yaw_rate;
      timer = 0;
      while (timer < (M_PI/2.0))
      {
            ROS_INFO_STREAM("Left");
            twist_commander.publish(twist_cmd);
            timer += sample_dt;
            loop_timer.sleep();
      }

      // Running straight
      twist_cmd.linear.x = speed; //command to move forward
      twist_cmd.angular.z = 0;
      timer = 0;
      while (timer < 2.3)
      {
            ROS_INFO_STREAM("Straight");
            twist_commander.publish(twist_cmd);
            timer += sample_dt;
            loop_timer.sleep();
      }

      // Rotate right
      twist_cmd.linear.x = 0;
      twist_cmd.angular.z = -yaw_rate;
      timer = 0;
      while (timer < (M_PI/2.0))
      {
            ROS_INFO_STREAM("Right");
            twist_commander.publish(twist_cmd);
            timer += sample_dt;
            loop_timer.sleep();
      }

      // Running straight
      twist_cmd.linear.x = speed; //command to move forward
      twist_cmd.angular.z = 0;
      timer = 0;
      while (timer < 3.5)
      {
            ROS_INFO_STREAM("Straight");
            twist_commander.publish(twist_cmd);
            timer += sample_dt;
            loop_timer.sleep();
      }

      // Rotate left
      twist_cmd.linear.x = 0;
      twist_cmd.angular.z = yaw_rate;
      timer = 0;
      while (timer < (M_PI/2.0))
      {
            ROS_INFO_STREAM("Left");
            twist_commander.publish(twist_cmd);
            timer += sample_dt;
            loop_timer.sleep();
      }

      // Running straight
      twist_cmd.linear.x = speed; //command to move forward
      twist_cmd.angular.z = 0;
      timer = 0;
      while (timer < 3)
      {
            ROS_INFO_STREAM("Straight");
            twist_commander.publish(twist_cmd);
            timer += sample_dt;
            loop_timer.sleep();
      }

      // Rotate left
      twist_cmd.linear.x = 0;
      twist_cmd.angular.z = yaw_rate;
      timer = 0;
      while (timer < (M_PI/2.0))
      {
            ROS_INFO_STREAM("Left");
            twist_commander.publish(twist_cmd);
            timer += sample_dt;
            loop_timer.sleep();
      }

      // Running straight
      twist_cmd.linear.x = speed; //command to move forward
      twist_cmd.angular.z = 0;
      timer = 0;
      while (timer < 3.7)
      {
            ROS_INFO_STREAM("Straight");
            twist_commander.publish(twist_cmd);
            timer += sample_dt;
            loop_timer.sleep();
      }

      // Rotate right
      twist_cmd.linear.x = 0;
      twist_cmd.angular.z = -yaw_rate;
      timer = 0;
      while (timer < (M_PI/2.0))
      {
            ROS_INFO_STREAM("Right");
            twist_commander.publish(twist_cmd);
            timer += sample_dt;
            loop_timer.sleep();
      }

      // Running straight
      twist_cmd.linear.x = speed; //command to move forward
      twist_cmd.angular.z = 0;
      timer = 0;
      while (timer < 6.9)
      {
            ROS_INFO_STREAM("Straight");
            twist_commander.publish(twist_cmd);
            timer += sample_dt;
            loop_timer.sleep();
      }

      // Rotate right
      twist_cmd.linear.x = 0;
      twist_cmd.angular.z = yaw_rate;
      timer = 0;
      while (timer < (M_PI/2.0))
      {
            ROS_INFO_STREAM("Left");
            twist_commander.publish(twist_cmd);
            timer += sample_dt;
            loop_timer.sleep();
      }

      // Running straight
      twist_cmd.linear.x = speed; //command to move forward
      twist_cmd.angular.z = 0;
      timer = 0;
      while (timer < 3.5)
      {
            ROS_INFO_STREAM("Straight");
            twist_commander.publish(twist_cmd);
            timer += sample_dt;
            loop_timer.sleep();
      }

      //halt the motion
      twist_cmd.angular.z = 0.0;
      twist_cmd.linear.x = 0.0;
      for (int i = 0; i < 10; i++)
      {
            twist_commander.publish(twist_cmd);
            loop_timer.sleep();
      }
      //done commanding the robot; node runs to completion
}