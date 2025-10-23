Pod::Spec.new do |s|
  s.name             = 'TapTapProfileSDK'
  s.version          = '4.8.4-beta.1'
  s.summary          = '提供 TapTap 展示用户名片信息的能力。'
  s.swift_version    = '5.0'
  s.description      = <<-DESC
  提供 TapTap 用户名片信息的能力。
                       DESC

  s.homepage         = 'https://github.com/taptap/TapSDK4-frameworks'
  s.license          = { :type => "MIT" }
  s.author           = 'TapTap'
  s.source           = { :git => 'https://github.com/taptap/TapSDK4-frameworks.git', :tag => s.version.to_s }

  s.ios.deployment_target = '11.0'
  s.static_framework = true
  s.vendored_frameworks = "Frameworks/TapTapProfileSDK.xcframework"
  s.resources = 'Frameworks/TapTapProfileResource.bundle'
  s.dependency 'TapTapLoginSDK', s.version.to_s
  s.dependency "Kingfisher", '~> 6.0'

end
