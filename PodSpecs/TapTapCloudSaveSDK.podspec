Pod::Spec.new do |s|
  s.name             = 'TapTapCloudSaveSDK'
  s.version          = '4.8.4-beta.0'
  s.summary          = '提供 TapTap 云存档的能力。'
  s.swift_version    = '5.0'
  s.description      = <<-DESC
  提供 TapTap 同步云存档数据的能力。
                       DESC

  s.homepage         = 'https://github.com/taptap/TapSDK4-frameworks'
  s.license          = { :type => "MIT" }
  s.author           = 'TapTap'
  s.source           = { :git => 'https://github.com/taptap/TapSDK4-frameworks.git', :tag => s.version.to_s }

  s.ios.deployment_target = '11.0'
  s.static_framework = true
  s.vendored_frameworks = "Frameworks/TapTapCloudSaveSDK.xcframework", "Frameworks/cloudsave_sdk.xcframework"
  s.dependency 'TapTapLoginSDK', s.version.to_s
  s.xcconfig = {
    'OTHER_LDFLAGS' => '-lz.1'
  }
  
end
