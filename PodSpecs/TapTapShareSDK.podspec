Pod::Spec.new do |s|
  s.name             = 'TapTapShareSDK'
  s.version          = '4.7.0-beta.8'
  s.summary          = '提供分享数据到 Tap 客户端的能力。'
  s.swift_version    = '5.0'
  s.description      = <<-DESC
  提供分享数据到 Tap 客户端的能力。
                       DESC

  s.homepage         = 'https://github.com/taptap/TapSDK4-frameworks'
  s.license          = { :type => "MIT" }
  s.author           = 'TapTap'
  s.source           = { :git => 'https://github.com/taptap/TapSDK4-frameworks.git', :tag => s.version.to_s }

  s.ios.deployment_target = '11.0'
  s.static_framework = true
  s.vendored_frameworks = "Frameworks/TapTapShareSDK.xcframework"
  s.dependency 'TapTapCoreSDK', s.version.to_s

end
