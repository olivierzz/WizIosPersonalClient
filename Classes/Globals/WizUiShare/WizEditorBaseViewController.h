//
//  WizEditorBaseViewController.h
//  Wiz
//
//  Created by wiz on 12-7-2.
//
//

#import <UIKit/UIKit.h>
#import "UIWebView+WizEditor.h"
#import "VoiceRecognition.h"

@class WizDocument;
@protocol WizEditorSourceDelegate <NSObject>
- (NSString*) editorSourcePath:(NSString*)path;
@end

@interface WizEditorBaseViewController : UIViewController <WizVoiceRecognitionDelegate, UITextFieldDelegate>
{
    WizDocument* docEdit;
    NSMutableArray* attachmentsArray;
    id<WizEditorSourceDelegate> sourceDelegate;
    //
    UIWebView* editorWebView;
    UITextField* titleTextField;
    //
    NSURLRequest* urlRequest;
    
    NSString* currentDeleteImagePath;
    //
    VoiceRecognition* voiceRecognitionView;
    //
}
@property (nonatomic, retain) WizDocument* docEdit;
@property (nonatomic, assign) id<WizEditorSourceDelegate> sourceDelegate;
@property (nonatomic, retain) NSURLRequest* urlRequest;
@property (nonatomic, retain)  NSString* currentDeleteImagePath;
@property (nonatomic, retain) VoiceRecognition* voiceRecognitionView;
//
- (id) initWithWizDocument:(WizDocument*)doc;
//
- (BOOL) canRecord;
- (BOOL) startRecord;
- (BOOL) isRecording;
- (BOOL) stopRecord;
- (BOOL) canSnapPhotos;
- (UIImagePickerController*) selectPhoto:(id<UIImagePickerControllerDelegate, UINavigationControllerDelegate>) parentController;
- (UIImagePickerController*) snapPhoto:(id<UIImagePickerControllerDelegate, UINavigationControllerDelegate>)parentController;
//
- (void) willAddAudioDone:(NSString*)audioPath;
- (void) willAddPhotoDone:(NSString*)photoPath;
//


//
- (NSURL*) buildEditorEnviromentLessThan5;
- (NSURL*) buildEditorEnviromentMoreThan5;
//
- (void) willDeleteImage:(NSString*)sourcePath;
//
- (void) resumeLastEditong;

- (NSString*) editingFilePath;
- (NSString*) editingIndexFilePath;
- (NSString*) editingMobileFilePath;
- (NSString*) editingHtmlModelFilePath;
- (NSString*) editingDocumentModelFilePath;

//
- (void) resizeBackgrouScrollViewFrame:(CGRect)rect;
- (void) resizeBackgrouScrollViewStartY:(CGFloat)startY height:(CGFloat)height;
- (void) prepareForSave;
@end
