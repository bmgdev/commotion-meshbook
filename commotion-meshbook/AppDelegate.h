//
//  AppDelegate.h
//  commotion-meshbook
//
//  Created by Brad : Scal.io, LLC - http://scal.io
//

#import <Cocoa/Cocoa.h>
#import "NetworkService.h"
#import "OLSRDService.h"

@interface AppDelegate : NSObject <NSApplicationDelegate, NSMenuDelegate> {

    // view controller setup
    NSWindowController *_settingsWindowController;
    NetworkService *NetworkServiceClass;
    
    // Menu Items
	NSStatusItem *statusItem;
	IBOutlet NSMenu *statusMenu;
	IBOutlet NSMenuItem *menuQuit;

    // Menu Items - Network
    NSDictionary *fetchedUserWifiData;
    NSString *fetchedWifiState;
    NSString *fetchedWifiSSID;
    NSString *fetchedWifiBSSID;
    NSString *fetchedWifiChannel;
    BOOL wifiOn;
    
	IBOutlet NSMenuItem *menuNetworkStatus;
    IBOutlet NSMenuItem *menuNetworkSSID;
    IBOutlet NSMenuItem *menuNetworkBSSID;
    IBOutlet NSMenuItem *menuNetworkChannel;
    // Menu Items - Mesh
    OLSRDService *olsrdProcess;
    IBOutlet NSMenuItem *menuMeshSSID;
    IBOutlet NSMenuItem *menuMeshStatus;
    IBOutlet NSMenuItem *menuSelectedNetwork;
    IBOutlet NSMenuItem *menuActiveMesh;    
    
    NSInteger tag1Index;
    NSInteger profileCount;
    
    NSArray *scannedItems;
}

@property (nonatomic, readonly) NSWindowController *settingsWindowController;
@property (nonatomic) NSInteger focusedAdvancedControlIndex; // maspref 
@property (strong) NSMutableArray *profiles; // dynamic menu items

#pragma mark -
#pragma mark NSMenu Delegate
- (void)menuWillOpen:(NSMenu *)menu;
- (void)menuNeedsUpdate:(NSMenu *)menu;
- (void)setChosenNetwork:(NSMenuItem *)selectedNetwork;

#pragma mark -
#pragma mark Network / Mesh Data Setup & Processing
- (void)initNetworkInterface;
- (void)initMeshInterface;
- (void)updateUserWifiMenuItems:(NSNotification *)fetchedWifiData;
- (void)updateMeshMenuItems:(NSNotification *)fetchedMeshData;

#pragma mark -
#pragma mark Menu / Window Controller
- (NSWindowController *)settingsWindowController;
- (IBAction) openSettings:(id)sender;
- (NSInteger)focusedAdvancedControlIndex;
- (void)setFocusedAdvancedControlIndex:(NSInteger)focusedAdvancedControlIndex;

#pragma mark -
#pragma mark Reachability
- (BOOL)isWifiOn;

@end
