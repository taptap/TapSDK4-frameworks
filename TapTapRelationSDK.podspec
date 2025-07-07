Pod::Spec.new do |s|
  s.name             = 'TapTapRelationSDK'
  s.version          = '4.7.0'
  s.summary          = '好友 SDK'
  s.swift_version    = '5.0'
  s.description      = <<-DESC
  展示好友列表，提供聊天功能
                       DESC

  s.homepage         = 'https://github.com/taptap/TapSDK4-frameworks'
  s.license          = { :type => "MIT" }
  s.author           = 'TapTap'
  s.source           = { :git => 'https://github.com/taptap/TapSDK4-frameworks.git', :tag => s.version.to_s }

  s.ios.deployment_target = '13.0'
  s.static_framework = true
  s.vendored_frameworks = "Frameworks/TapTapRelationSDK.xcframework", "Frameworks/bifrost_sdk.xcframework"
  s.resources = 'Frameworks/TapTapRelationResource.bundle'
  s.dependency 'TapTapLoginSDK', s.version.to_s

  s.frameworks = 'UIKit',
                 'Foundation',
                 'CoreTelephony',
                 'SystemConfiguration',
                 'AdSupport',
                 'GameController'
  s.library = 'c++'

end
