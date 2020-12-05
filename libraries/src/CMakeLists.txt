include_directories( ${PROJECT_SOURCE_DIR}/libraries/inc)
add_library(interim
  STATIC
    Aircylinder.cpp
    CommuBase.cpp
    Localization.cpp
    Motor.cpp
    MotorSystem.cpp
    RobotSerial.cpp
    RotaryEncoder.cpp
    Sensor.cpp
  )

# PROJECT_SOURCE_DIRはこのプロジェクトのルートディレクトリの絶対パス
target_include_directories(interim PUBLIC ${PROJECT_SOURCE_DIR}/libraries/include)