Pod::Spec.new do |s|
  s.name             = 'TapTapRelationLiteSDK'
  s.version          = '4.8.3'
  s.summary          = '提供 TapTap 获取好友数据、邀请好友的能力。'
  s.swift_version    = '5.0'
  s.description      = <<-DESC
  提供 TapTap 获取好友数据、邀请好友的能力。
                       DESC

  s.homepage         = 'https://github.com/taptap/TapSDK4-frameworks'
  s.license          = { :type => "MIT" }
  s.author           = 'TapTap'
  s.source           = { :git => 'https://github.com/taptap/TapSDK4-frameworks.git', :tag => s.version.to_s }

  s.ios.deployment_target = '11.0'
  s.static_framework = true
  s.vendored_frameworks = "Frameworks/TapTapRelationLiteSDK.xcframework"
  s.resources = 'Frameworks/TapTapRelationLiteResource.bundle'
  s.dependency 'TapTapProfileSDK', s.version.to_s

end
