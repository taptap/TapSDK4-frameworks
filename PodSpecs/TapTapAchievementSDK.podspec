Pod::Spec.new do |s|
  s.name             = 'TapTapAchievementSDK'
  s.version          = '4.8.1-beta.7'
  s.summary          = '提供 TapTap 同步及展示成就数据的能力。'
  s.swift_version    = '5.0'
  s.description      = <<-DESC
  提供 TapTap 同步及展示成就数据的能力。
                       DESC

  s.homepage         = 'https://github.com/taptap/TapSDK4-frameworks'
  s.license          = { :type => "MIT" }
  s.author           = 'TapTap'
  s.source           = { :git => 'https://github.com/taptap/TapSDK4-frameworks.git', :tag => s.version.to_s }

  s.ios.deployment_target = '11.0'
  s.static_framework = true
  s.vendored_frameworks = "Frameworks/TapTapAchievementSDK.xcframework"
  s.resources = 'Frameworks/TapTapAchievementResource.bundle'
  s.dependency 'TapTapLoginSDK', s.version.to_s

end
