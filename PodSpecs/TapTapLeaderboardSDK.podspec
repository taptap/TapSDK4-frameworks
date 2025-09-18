Pod::Spec.new do |s|
  s.name             = 'TapTapLeaderboardSDK'
  s.version          = '4.8.2-beta.1'
  s.summary          = '提供 TapTap 排行榜能力。'
  s.swift_version    = '5.0'
  s.description      = <<-DESC
  提供 TapTap 排行榜能力。
                       DESC

  s.homepage         = 'https://github.com/taptap/TapSDK4-frameworks'
  s.license          = { :type => "MIT" }
  s.author           = 'TapTap'
  s.source           = { :git => 'https://github.com/taptap/TapSDK4-frameworks.git', :tag => s.version.to_s }

  s.ios.deployment_target = '11.0'
  s.static_framework = true
  s.vendored_frameworks = "Frameworks/TapTapLeaderboardSDK.xcframework"
  s.resources = 'Frameworks/TapTapLeaderboardResource.bundle'
  s.dependency 'TapTapProfileSDK', s.version.to_s

end
