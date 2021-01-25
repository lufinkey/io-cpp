#
# Be sure to run `pod lib lint IOCpp.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
	s.name             = 'IOCpp'
	s.version          = '0.1.0'
	s.summary          = 'A small I/O library for C++.'

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

	s.description      = <<-DESC
	A small I/O library for C++.
							DESC

	s.homepage         = 'https://github.com/lufinkey/io-cpp'
	# s.screenshots     = 'www.example.com/screenshots_1', 'www.example.com/screenshots_2'
	# s.license          = { :type => 'MIT', :file => 'LICENSE' }
	s.author           = { 'Luis Finke' => 'luisfinke@gmail.com' }
	s.source           = { :git => 'https://github.com/lufinkey/io-cpp.git', :tag => s.version.to_s }
	s.social_media_url = 'https://twitter.com/lufinkey'

	s.ios.deployment_target = '13.0'
	s.osx.deployment_target = '10.14'

	s.source_files = 'src/fgl/**/*'
  
	# s.resource_bundles = {
	#   'IOCpp' => ['IOCpp/Assets/*.png']
	# }

	s.public_header_files = 'src/fgl/**/*.hpp'
	s.header_mappings_dir = 'src/fgl'
	s.pod_target_xcconfig = {
		'HEADER_SEARCH_PATHS' => [
			"$(PODS_ROOT)/IOCpp/src",
			"$(PODS_ROOT)/DataCpp/src",
			"$(PODS_ROOT)/AsyncCpp/src",
			"$(PODS_ROOT)/dtl"
		],
		'CLANG_CXX_LANGUAGE_STANDARD' => 'gnu++17',
		'GCC_OPTIMIZATION_LEVEL' => 's'
	}
	s.user_target_xcconfig = {
		'FRAMEWORK_SEARCH_PATHS' => "${PODS_ROOT}/IOCpp/src"
	}
	# s.frameworks = 'UIKit', 'MapKit'
	s.dependency 'DataCpp' # git@github.com:lufinkey/data-cpp.git
	s.dependency 'AsyncCpp' # git@github.com:lufinkey/async-cpp.git
end
