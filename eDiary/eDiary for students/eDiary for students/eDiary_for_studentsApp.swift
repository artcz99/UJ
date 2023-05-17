//
//  eDiary_for_studentsApp.swift
//  eDiary for students
//
//  Created by Artur on 13/05/2023.
//

import SwiftUI

@main
struct eDiary_for_studentsApp: App {
    let persistenceController = PersistenceController.shared

    var body: some Scene {
        WindowGroup {
            ContentView()
                .environment(\.managedObjectContext, persistenceController.container.viewContext)
        }
    }
}
