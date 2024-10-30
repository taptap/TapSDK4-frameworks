Pod::Spec.new do |s|
  s.name             = 'TapTapComplianceSDK'
  s.version          = '4.4.3'
  s.summary          = '提供 TapTap 合规认证能力。'

  s.description      = <<-DESC
  提供 TapTap 合规认证能力。
                       DESC

  s.homepage         = 'https://github.com/taptap/TapSDK4-frameworks'
  s.license          = { :type => "MIT" }
  s.author           = 'TapTap'
  s.source           = { :git => 'https://github.com/taptap/TapSDK4-frameworks.git', :tag => s.version.to_s }

  s.ios.deployment_target = '11.0'
  s.static_framework = true
  s.vendored_frameworks = "Frameworks/TapTapComplianceSDK.xcframework"
  s.resources = 'Frameworks/TapTapComplianceResource.bundle'
  s.dependency 'TapTapLoginSDK', s.version.to_s

end
