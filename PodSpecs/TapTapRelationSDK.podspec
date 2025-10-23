Pod::Spec.new do |s|
  s.name             = 'TapTapRelationSDK'
  s.version          = '4.8.4-alpha.127'
  s.summary          = '提供 TapTap 展示好友 UI 的能力。'
  s.swift_version    = '5.0'
  s.description      = <<-DESC
  提供 TapTap 展示好友 UI 的能力。
                       DESC

  s.homepage         = 'https://github.com/taptap/TapSDK4-frameworks'
  s.license          = { :type => "MIT" }
  s.author           = 'TapTap'
  s.source           = { :git => 'https://github.com/taptap/TapSDK4-frameworks.git', :tag => s.version.to_s }

  s.ios.deployment_target = '11.0'
  s.static_framework = true
  s.vendored_frameworks = "Frameworks/TapTapRelationSDK.xcframework", "Frameworks/bifrost_sdk.xcframework"
  s.resources = 'Frameworks/TapTapRelationResource.bundle'
  s.dependency 'TapTapProfileSDK', s.version.to_s

end
