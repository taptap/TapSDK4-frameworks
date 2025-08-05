Pod::Spec.new do |s|
  s.name             = 'TapTapMomentSDK'
  s.version          = '4.7.0-beta.5'
  s.summary          = '提供 TapTap 内嵌动态功能。'
  s.swift_version    = '5.0'
  s.description      = <<-DESC
  提供 TapTap 内嵌动态功能。
                       DESC

  s.homepage         = 'https://github.com/taptap/TapSDK4-frameworks'
  s.license          = { :type => "MIT" }
  s.author           = 'TapTap'
  s.source           = { :git => 'https://github.com/taptap/TapSDK4-frameworks.git', :tag => s.version.to_s }

  s.ios.deployment_target = '11.0'
  s.static_framework = true
  s.vendored_frameworks = "Frameworks/TapTapMomentSDK.xcframework"
  s.resources = 'Frameworks/TapTapMomentResource.bundle'
  s.dependency 'TapTapLoginSDK', s.version.to_s

end
